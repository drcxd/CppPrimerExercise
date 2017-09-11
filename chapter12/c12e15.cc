struct connection;

void disconnect(connection c);

auto f = [] (connection *p) -> void {
    disconnect(*p);
}
