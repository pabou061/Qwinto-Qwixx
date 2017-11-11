# Qwinto-Qwixx
https://codereview.stackexchange.com/questions/31571/random-number-generation-in-dice-class


/////////////////////////////////////////////////////
/// classes
/////////////////////////////////////////////////////

class VectorValues {
private:
    vector<int> v = vector<int>(10);

public:
    vector<int>::iterator begin(){
        return v.begin();
    }
    vector<int>::iterator end(){
        return v.end();
    }
    vector<int>::const_iterator begin() const {
        return v.begin();
    }
    vector<int>::const_iterator end() const {
        return v.end();
    }
};