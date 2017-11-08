void StrBlob::push_back(std::string &&t) {
    data->push_back(std::move(t));
}
