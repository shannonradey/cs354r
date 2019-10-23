#include <Node.hpp>

#include <Godot.hpp>
#include <PackedScene.hpp>

namespace godot
{

class Network : public Node
{
    GODOT_CLASS(Network, Node)

public:
    static void _register_methods();

    Network();
    ~Network();

    void _init();
    void _ready();

    void create_server(String playerNickname);
    void connect_to_server(String playerNickname);
    void _connected_to_server();
    void _on_player_disconnected(int64_t id);
    void _on_player_connected(int64_t connectedPlayerId);
    void _request_player_info(int64_t requestFromId, int64_t playerId);
    void _request_players(int64_t requestFromId);
    void _send_player_info(int64_t id, Dictionary info);
    void update_position(int64_t id, Transform position);

private:
    Ref<PackedScene> PlayerScene;
    const String SERVER_IP = "127.0.0.1";
    const int64_t SERVER_PORT = 31400;
    const int64_t MAX_PLAYERS = 5;
    Dictionary selfData;
    Dictionary players;
};

}