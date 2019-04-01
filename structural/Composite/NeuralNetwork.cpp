#include <iostream>
#include <vector>
class Neuron;

template<typename Self>
struct SomeNeuron
{
    template<typename T> void connectTo(T& other)
    {
        for(Neuron& from : *static_cast<Self*>(this))
        {
            for(Neuron& to : other)
            {
                from.out_.push_back(&to);
                to.in_.push_back(&from);
            }
        }
    }
};

struct Neuron : SomeNeuron<Neuron>
{
        Neuron()
        {
            static int id{0};
            this->id_ = id++;
        }
 
        Neuron* begin() { return this; };
        Neuron* end() { return (this+1); };
        /* void connectTo(Neuron& other)
        {
            out_.push_back(&other);
            other.in_.push_back(this);
        } */

        friend std::ostream& operator<<(std::ostream& os, const Neuron& obj)
        {
            for(Neuron* n : obj.in_)
            {
                os << n->id_ << "\t-->\t" << "["<< obj.id_ <<"]"<<"\n";
            }

            for(Neuron* n : obj.out_)
            {
                os << "[" << obj.id_ << "]" <<"\t-->\t" << n->id_ <<"\n";
            }

            return os;
        }

        int id_;
        std::vector<Neuron*> in_;
        std::vector<Neuron*> out_;
};

struct NeuronLayer : std::vector<Neuron>, SomeNeuron<NeuronLayer>
{
        NeuronLayer(int count)
        {
            while(count-- > 0)
            {
                push_back(Neuron{});
            }
        }

        friend std::ostream& operator<<(std::ostream& os, NeuronLayer& obj)
        {
            for(auto n : obj)
            {
                os << n;
            }
            return os;
        }
};

int main(int argc, char const *argv[])
{
    Neuron n1{};
    Neuron n2{};

    n1.connectTo(n2);

    std::cout << n1;
    std::cout << n2;

    NeuronLayer layer1{4}, layer2{3};
    layer1.connectTo(layer2);

    std::cout << layer1;
    std::cout << layer2;

    return 0;
}
