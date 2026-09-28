const std = @import("std");
const fmt = std.fmt;

pub fn create(io: std.Io, name: []const u8) !void {
    var dir: std.Io.Dir = try std.Io.Dir.cwd().openDir(io, ".", .{ .iterate = true });
    defer dir.close(io);

    try dir.createDir(io, name, std.Io.File.Permissions.default_dir);
    const app_dir = try dir.openDir(io, name, .{ .iterate = true });
    defer app_dir.close(io);

    const file = try app_dir.createFile(io, "main.norm", .{ .read = true, .truncate = true });
    defer file.close(io);

    try file.writeStreamingAll(io, "@app");

    std.debug.print("init project `{s}`\n", .{name});
}
