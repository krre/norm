const std = @import("std");
const cli = @import("cli.zig");

pub fn main(init: std.process.Init) !void {
    const io = init.io;

    const arena: std.mem.Allocator = init.arena.allocator();
    const args = try init.minimal.args.toSlice(arena);

    try cli.run(io, args[1..]);
}
