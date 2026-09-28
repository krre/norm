const project = @import("project.zig");
const std = @import("std");

pub fn init(io: std.Io, name: []const u8) !void {
    try project.create(io, name);
}

pub fn build() !void {
    std.log.info("build", .{});
}

pub fn run() !void {
    std.log.info("run", .{});
}
