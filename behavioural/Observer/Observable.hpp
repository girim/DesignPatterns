#include <vector>
#include <algorithm>

template <typename> struct Observer;

template<typename T>
struct Observable
{
    std::vector<Observer<T>*> observers_;

    public:
        virtual void subscribe(Observer<T>& observer)
        {
            observers_.push_back(&observer);
        }

        virtual void unsubscribe(Observer<T>& observer)
        {
            observers_.erase(std::remove(observers_.begin(), observers_.end(), &observer), observers_.end());
        }

        virtual void notify(T& source, const std::string& fieldName)
        {
            for(auto observer : observers_)
            {
                observer->field_changed(source, fieldName);
            }
        }
};
