#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class HtmlElement
{
    public:
        HtmlElement(){};
        HtmlElement(std::string name, std::string text) : name_(name), text_(text){};

        std::string getName() const 
        { 
            return this->name_;
        }

        void setName(std::string name) 
        {
            this->name_ = name;
        }

        std::string getText() const
        {
            return this->text_;
        }

        void setText(std::string text)
        {
            this->text_ = text;
        }

        std::string str(int indent = 0) const
        {
            std::ostringstream oss;
            std::string space(indentSize * indent, ' ');

            //open tag
            oss << space << "<" << name_ << ">" << std::endl;

            if(text_.size() >  0)
            {
                oss << std::string(indentSize * (indent + 1), ' ') << text_ << std::endl;
            }
            
            for(const auto& element : elements_)
            {
                oss << element.str(indent + 1);
            }

            //close tag
            oss << space << "</" << name_ << ">" << std::endl;

            return oss.str();
        }

        void addElements(const HtmlElement& element)
        {
            elements_.push_back(element);
        }
    private:
        std::string name_;
        std::string text_;
        std::vector<HtmlElement> elements_;
        const unsigned int indentSize = 2;
};

/* API to build the HtmlElement */
class HtmlBuilder
{
    public:
        explicit HtmlBuilder(std::string rootName) 
        {
            rootElement_.setName(rootName);
        }

        HtmlBuilder& addChildElements(std::string name, std::string text)
        {
            HtmlElement element{name, text};
            rootElement_.addElements(element);
            return *this;
        }

        std::string str() const
        {
            return rootElement_.str();
        }

    private:
        HtmlElement rootElement_;
};

int main(int argc, char const *argv[])
{
    HtmlBuilder builder{"ul"};
    builder.addChildElements("il", "Hello").addChildElements("il","C++");

    std::cout << builder.str() << "\n";

    return 0;
}
