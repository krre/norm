const std = @import("std");

pub fn init(io: std.Io, name: []const u8) !void {
    _ = io;
    std.log.info("init {s}", .{name});
}

pub fn build() !void {
    std.log.info("build", .{});
}

pub fn run() !void {
    std.log.info("run", .{});
}
