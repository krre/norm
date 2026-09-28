const build_options = @import("build_options");
const command = @import("command.zig");
const std = @import("std");
const fatal = std.process.fatal;

const usage =
    \\Usage: norm [options] [command]
    \\
    \\Options:
    \\  -h, --help     Print help and exit
    \\  -v, --version  Print version information and exit
    \\
    \\Commands:
    \\  init           Init new project
    \\  build          Build project
    \\  run            Run application
    \\
;

pub fn run(io: std.Io, args: []const []const u8) !void {
    var buffer: [1024]u8 = undefined;
    var writer = std.Io.File.stdout().writer(io, &buffer);

    if (args.len == 0) {
        try writer.interface.writeAll(usage);
        try writer.interface.flush();
        return;
    }

    const arg = args[0];

    if (std.mem.startsWith(u8, arg, "-")) {
        if (std.mem.eql(u8, arg, "-v") or std.mem.eql(u8, arg, "--version")) {
            try writer.interface.print("{s}\n", .{build_options.version});
            try writer.interface.flush();
            return;
        } else if (std.mem.eql(u8, arg, "-h") or std.mem.eql(u8, arg, "--help")) {
            try writer.interface.writeAll(usage);
            try writer.interface.flush();
            return;
        } else {
            fatal("unrecognized option: '{s}'", .{arg});
        }
    }

    const command_name = arg;

    if (std.mem.eql(u8, command_name, "init")) {
        if (args.len < 2) {
            fatal("project name is empty", .{});
        } else {
            try command.init(io, args[1]);
        }
    } else if (std.mem.eql(u8, command_name, "build")) {
        try command.build();
    } else if (std.mem.eql(u8, command_name, "run")) {
        try command.run();
    } else {
        fatal("unknown command: '{s}'", .{command_name});
    }
}
