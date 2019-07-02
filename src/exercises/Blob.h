#pragma once

#include <vector>
#include <memory>

class StrBlob {
	friend class StrBlobPtr;
public: 
	typedef std::vector<std::string>::size_type size_type; 

	StrBlob(); 
	StrBlob(std::initializer_list<std::string> il);

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); } 
	
	// add and remove elements 
	void push_back(const std::string &t) {data->push_back(t);}
	void pop_back();
	
	// element access 
	std::string& front();

	const std::string& front() const;
		
	std::string& back();
	const std::string& back() const;

	StrBlobPtr begin();
	StrBlobPtr end();

private:
	std::shared_ptr<std::vector<std::string>> data; 
	// throws msg if data[i] isn't valid 
	void check(size_type i, const std::string &msg) const;
};

class StrBlobPtr {
public: StrBlobPtr() : curr(0) { }
		StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) { }
		std::string& deref() const;
		StrBlobPtr& incr();
		// prefix version
private: // check returns a shared_ptr to the vector if the check succeeds
	std::shared_ptr<std::vector<std::string>> check(std::size_t size, const std::string& msg) const;
		 // store a weak_ptr, which means the underlying vector might be destroyed
	std::weak_ptr<std::vector<std::string>> wptr; std::size_t curr;
		 // current position within the array
};