class SuperClass
{
    public:
        int val;

        SuperClass(int foo)
        {
            // do something with foo
            val = foo;
        }
};

class SubClass : public SuperClass
{
    public:
        int val;
        int val2;

        SubClass(int foo, int bar)
        : SuperClass(foo)    // Call the superclass constructor in the subclass' initialization list.
        {
            // do something with bar
            val = foo;
            val2 = bar;
        }
};

int main() {

    SuperClass super(0);

    SubClass sub(0, 1);

    return 0;
}