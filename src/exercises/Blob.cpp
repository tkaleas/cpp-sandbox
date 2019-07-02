#include <string>
#include <vector>
#include <memory>

#include "Blob.h"

using namespace std;

/*StrBlob Method Definitions*/

StrBlob::StrBlob() :
	data(std::make_shared<vector<string>>()) { }

StrBlob::StrBlob(initializer_list<string> il) : 
	data(make_shared<vector<string>>(il)) { }

void StrBlob::check(size_type i, const string &msg) const {
	if (i >= data->size()) 
		throw out_of_range(msg);
}

string& StrBlob::front() {
	// if the vector is empty, check will throw 
	check(0, "front on empty StrBlob"); 
	return data->front();
} 

string& StrBlob::back() {
	check(0, "back on empty StrBlob");
	return data->back();
} 

const string& StrBlob::front() const {
	// if the vector is empty, check will throw 
	check(0, "front on empty StrBlob");
	const string& front = data->front(); //not necessary but testing const functionality
	return front;
} 

const string& StrBlob::back() const {
	check(0, "back on empty StrBlob");
	const string& back = data->back();
	return back;
}

void StrBlob::pop_back() {
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

StrBlobPtr StrBlob::begin() {
	return StrBlob(*this);
}

StrBlobPtr StrBlob::end() {
	return StrBlobPtr(*this, data->size());
}

/*StrBlobPtr Method Definitions*/
std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t size, const std::string& msg) const {
	std::shared_ptr<std::vector<std::string>> ptr =  wptr.lock();
	if (!ptr)
		throw runtime_error("Strblob unbound");
	if (size > ptr->size())
		throw std::out_of_range(msg.c_str());
	return ptr;
}

std::string& StrBlobPtr::deref() const {
	std::shared_ptr<std::vector<std::string>> ptr = check(curr, "out of bounds");
	return (*ptr)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
	std::shared_ptr<std::vector<std::string>> ptr = check(curr, "out of bounds");
	++curr;
	return *this;
}