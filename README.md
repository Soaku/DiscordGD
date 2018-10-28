# DiscordGD

Discord Rich Presence for Godot Game Engine 3.1, using GDNative.

Currently there isn't support for joining and spectating, but it will be added in the future.

## Installing

Download the [ZIP with latest release](https://github.com/Soaku/DiscordGD/releases) and paste it's content to your project. 

You can then use it by loading `res://gdnative/libdiscord.gdns` with `load` or `preload`, by adding it as singleton or by attaching as a script to existing node.

## Compiling

To compile, first you need to clone the repos into the DiscordGD directory:

- https://github.com/GodotNativeTools/godot-cpp (preffereably branch `nativescript-1.1`)
- https://github.com/discordapp/discord-rpc

  You need to compile Discord RPC with CMake, using the `BUILD_SHARED_LIBS` flag.
