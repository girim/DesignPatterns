#include <iostream>

typedef int Cable;

/* Target Interface */
struct USASocketInterface
{
    virtual int voltage() = 0;

    virtual Cable live() = 0;
    virtual Cable neutral() = 0;
};

/* Adaptee (Source) Interface */
struct EuropoianSocketInterface
{
    virtual int voltage() = 0;

    virtual Cable live() = 0;
    virtual Cable neutral() = 0;
    virtual Cable earth() = 0;
};

/* Adaptee */
struct EuroSocket : public EuropoianSocketInterface
{
    int voltage() override { return 230; }

    Cable live() override { return 1; }

    Cable neutral() override { return -1; }

    Cable earth() override { return 0; }
};

/* Adapter class */
class Adapter : public USASocketInterface
{
   public:
        Adapter(EuropoianSocketInterface& euroSocket) : euroSocket_(euroSocket){};
        
        virtual Cable live() override
        {
            return euroSocket_.live();
        }

        virtual Cable neutral() override
        {
            return euroSocket_.neutral();
        }

        virtual int voltage() override
        {
            return euroSocket_.voltage();
        }

   private:
        //Adaptee interface
        EuropoianSocketInterface& euroSocket_;
};

/* Client class */
class ElectricKettle
{
    public:
        ElectricKettle(USASocketInterface& usaSocket) : usaSocket_(usaSocket){}

        void boil()
        {
            if(usaSocket_.voltage() > 110)
            {
                std::cout << "Kettle is on fire...." << "\n";
            }

            if(usaSocket_.live() == 1 && usaSocket_.neutral() == -1)
            {
                std::cout << "coffee Time...." << "\n";
            }
        }

    private:
        USASocketInterface& usaSocket_;
};

int main(int argc, char const *argv[])
{
    EuroSocket euroSocket{};
    Adapter adapter{euroSocket};

    ElectricKettle eKettle{adapter};
    eKettle.boil();
    
    return 0;
}





