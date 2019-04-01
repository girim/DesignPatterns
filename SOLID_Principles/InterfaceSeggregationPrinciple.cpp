#include <iostream>

struct Document
{
    
};

/* struct IMachine
{
    virtual void print(Document& doc) = 0;
    virtual void scan(Document& doc) = 0;
    virtual void fax(Document& doc) = 0;
};

class MultiFunctionPrinter : public IMachine
{
    public:
        void print(Document& doc) override 
        {
            std::cout << "Printing the document ...." << "\n";
        }

        void scan(Document& doc) override
        {
            std::cout << "Scanning the document ...." << "\n";
        }

        void fax(Document& doc) override
        {
            std::cout << "Faxing the document ...." << "\n";
        }
};

class Scanner : public IMachine
{
    public:
        void print(Document& doc) override 
        {
            //what to fill here? either throw 'not implemented exception' or leave blank
        }

        void scan(Document& doc) override
        {
            std::cout << "Scanning the document ...." << "\n";
        }

        void fax(Document& doc) override
        {
            //what to fill here? either throw 'not implemented exception' or leave blank
        }
}; */

struct  IPrinter
{
    virtual void print(Document& doc) = 0; //pure virtual function & abstract base class/interface class
};

struct IScanner
{
    virtual void scan(Document& doc) = 0;
};

struct IFax
{
    virtual void fax(Document& doc) = 0;
};

struct  IMachine : public IPrinter, public IScanner, public IFax
{
};

struct Printer : public IPrinter
{
    void print(Document& doc) override
    {
        std::cout << "Printing doc...." << '\n';
    }
};

struct Scanner : public IScanner
{
    void scan(Document& doc) override
    {
        std::cout << "Scanning doc...." << "\n";
    }
};

struct Fax : public IFax
{
    void fax(Document& doc) override
    {
        std::cout << "Faxing doc...." << "\n";
    }
};


class MultiFunctionPrinter : public IMachine
{
    public:
        MultiFunctionPrinter(IPrinter& printer, IScanner& scanner, IFax& fax) : \
                                printer_(printer), scanner_(scanner), fax_(fax){};
        ~MultiFunctionPrinter(){};

        void print(Document& doc) override
        {
            printer_.print(doc);
        }

        void scan(Document& doc) override
        {
            scanner_.scan(doc);
        }

        void fax(Document& doc) override
        {
            fax_.fax(doc);
        }

    private:
        IPrinter& printer_;
        IScanner& scanner_;
        IFax& fax_;
};

int main(int argc, char const *argv[])
{
    Document doc;
    Printer ptr{};
    Scanner scr{};
    Fax fax{};
    MultiFunctionPrinter mfp{ptr, scr, fax};

    mfp.print(doc);
    mfp.scan(doc);
    mfp.fax(doc);

    return 0;
}



