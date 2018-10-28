# DiscordGD

Discord Rich Presence for Godot Game Engine 3.1, using GDNative.

Currently there isn't support for joining and spectating, but it will be added in the future.

## Installing

Download the [ZIP with latest release][releases] and paste it's content to your project. 

You can then use it by loading `res://gdnative/libdiscord.gdns` with `load` or `preload`, by adding it as singleton or by attaching as a script to existing node.

## Compiling

To compile, first you need to clone the repos into the DiscordGD directory:

- https://github.com/GodotNativeTools/godot-cpp (preffereably branch `nativescript-1.1`)
- https://github.com/discordapp/discord-rpc

  You need to compile Discord RPC with CMake, using the `BUILD_SHARED_LIBS` flag or get it from the compiled ZIP on the [releases] page.

## Properties

After you initialized the object, you need to connect with Discord using `start(app_id: String)`.

After that you can manage the rich presence by setting the properties:

- String `state`
- String `details`
- String `large_image_key`
- String `large_image_text`
- String `small_image_key`
- String `small_image_text`
- String `party_id`
- Int `party_size`
- Int `party_max`
- Int `start_time` (try using [`OS.get_unix_time()`](http://docs.godotengine.org/en/3.0/classes/class_os.html#class-os-get-unix-time))
- Int `end_time`
- String `spectate` (not working yet)
- String `join` (not working yet)

and then calling `update()`. You don't need to fill all of the properties.

  [releases]: https://github.com/Soaku/DiscordGD/releases
