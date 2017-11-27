class DebugDelete {
public:
    template <typename T> void operator(T *p) { delete p; }
};
