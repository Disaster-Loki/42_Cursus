template <typename T>
MutantStack::MutantStack(): v(NULL), lenght(0){
    std::cout << "MutantStack construtor called" << std::endl;
}

MutantStack::~MutantStack()
{
    std::cout << "MutantStack destrutor called" << std::endl;
}

MutantStack::MutantStack(const MutantStack &copy){
    *this = copy;
    std::cout << "MutantStack copy construtor called" << std::endl;
}

MutantStack &MutantStack::operator=(const MutantStack &copy){
    if (this != &copy){
        this->v = copy.v;
        this->length = copy.length;
    }
    return (*this);
}

void MutantStack::push(unsigned int value)
{
    v.push(value);
    std::cout << "Value add sucessfully" << std::endl;
}

//template <typename T>
unsigned int MutantStack::top()
{
    std::cout << "Value on top of MutantStack" << std::endl;
    return (v[v.size() - 1]);
}

void MutantStack::pop(){
    v.remove(MutantStack::top());
    std::cout << "pop sucessfully" << std::endl;
}

unsigned int MutantStack::size(){
    return (v.size());
}