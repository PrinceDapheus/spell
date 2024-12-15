
#include <iostream>
using namespace std;
#include <memory>


class phone {

    public:
    string name;
    int number;

//CONSTRUCTOR
    phone ( string n)
    : name(n)

    {

    cout << "Phone created !" <<endl;

    }

//DESTRUCTOR
    ~ phone(){

        cout << "Phone is destroyed!" <<endl;
    }

//PHONE CALL
    void call (int n){
    number = n;

        cout << "Calling...... "<< name << " : " << number <<endl;

    }

};






int main (){


// create shared pointer

shared_ptr<phone>phone1 = make_shared<phone>("Israel");


//Check use count
cout << "Use Count : " << phone1.use_count()<<endl;

// Create weak pointer linked to the shared pointer
weak_ptr<phone> weakMonitor = phone1;

// lock the weak pointer
//shared_ptr <phone> lockPointer = weakMonitor.lock();


//check is pointer is working

if (auto lockPointer = weakMonitor.lock()){

    cout << "weak pointer is locked : " << lockPointer->name << endl;
}
else {

    cout << "pointer null"<<endl;
}

// Reset the shared pointer

phone1.reset();


//Check use count
cout << "Use Count : " << phone1.use_count()<<endl;


// Try to lock the weak pointer again

if (auto lockPointer = weakMonitor.lock()){

    cout << "weak pointer is locked : " << lockPointer->name << endl;
}
else {

    cout << "pointer null"<<endl;
}

if (weakMonitor.expired()){

    cout << " link disconnected " <<endl;


}



    return 0;
}
