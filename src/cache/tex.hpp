class Tex
{
public:
    Tex(Tex &other) = delete;
    void operator= (const Tex &) = delete;

    static Tex* Cache();

    void say_hello();

private:
    Tex();
    ~Tex();

    static Tex* cache;
};

Tex* Tex::cache = nullptr;
