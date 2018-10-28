#include "discord.h"
#define memreset(name) memset(&name, 0, sizeof(name))
#define DEFPROP(type, name) void Discord::set_##name(type nw) { name = nw; } type Discord::get_##name() { return name; }
#define REGISTER(type, name, dfl) register_property<Discord, type>(#name, &Discord::set_##name, &Discord::get_##name, dfl);

using namespace godot;

void Discord::_register_methods() {
	register_method("start", &Discord::start);
	register_method("update", &Discord::update);
	REGISTER(String, details, "");
	REGISTER(String, state, "");
	REGISTER(String, large_image_key, "");
	REGISTER(String, small_image_key, "");
	REGISTER(String, large_image_text, "");
	REGISTER(String, small_image_text, "");
	REGISTER(int, party_size, 0);
	REGISTER(int, party_max, 0);
	REGISTER(long long, start_time, 0);
	REGISTER(long long, end_time, 0);
	REGISTER(String, spectate, "");
	REGISTER(String, join, "");
}

Discord::~Discord() {

	// add your cleanup here
	Discord_Shutdown();

}

DEFPROP(String, details);
DEFPROP(String, state);
DEFPROP(String, large_image_key);
DEFPROP(String, small_image_key);
DEFPROP(String, large_image_text);
DEFPROP(String, small_image_text);
DEFPROP(int, party_size);
DEFPROP(int, party_max);
DEFPROP(long long, start_time);
DEFPROP(long long, end_time);
DEFPROP(String, spectate);
DEFPROP(String, join);

void Discord::_init() {}

void Discord::start(String app) {

	// Add event handlers
	DiscordEventHandlers handlers;
	memreset(handlers);

	// Initialize Discord
	Discord_Initialize(app.ascii().get_data(), &handlers, 1, "");

}

void Discord::update() {

	// Create presence
	DiscordRichPresence presence;

	// Clear it
	memreset(presence);

	// Set properties
	presence.state = state.utf8().get_data();
	presence.details = details.utf8().get_data();
	presence.largeImageKey = large_image_key.utf8().get_data();
	presence.smallImageKey = small_image_key.utf8().get_data();
	presence.largeImageText = large_image_text.utf8().get_data();
	presence.smallImageText = small_image_text.utf8().get_data();
	presence.partyId = party_id.utf8().get_data();
	presence.partySize = party_size;
	presence.partyMax = party_max;
	presence.startTimestamp = start_time;
	presence.endTimestamp = end_time;
	presence.spectateSecret = spectate.utf8().get_data();
	presence.joinSecret = join.utf8().get_data();

	// Submit it
	Discord_UpdatePresence(&presence);

}