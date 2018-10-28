#ifndef DISCORD_H
#define DISCORD_H
#define PROP(type, name) type name; void Discord::set_##name(type nw); type Discord::get_##name();

#include <Godot.hpp>
#include <Node.hpp>
#include <discord_rpc.h>

namespace godot {

	class Discord : public Node {
		GODOT_CLASS(Discord, Node)

		public:

			PROP(String, state);
			PROP(String, details);
			PROP(String, large_image_key);
			PROP(String, small_image_key);
			PROP(String, large_image_text);
			PROP(String, small_image_text);
			PROP(String, party_id)
			PROP(int, party_size);
			PROP(int, party_max);
			PROP(long long, start_time);
			PROP(long long, end_time);
			PROP(String, spectate);
			PROP(String, join);

			static void _register_methods();

			~Discord();
			void _init();
			void start(String app);
			void update();
	};

}

#endif