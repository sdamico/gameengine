#ifndef SINGLETON_H
#define SINGLETON_H

template<typename T> class Singleton
{
	static T *inst;
	public:
	Singleton() {
		//if 32 bit change to short/int
		long offset = (long)(T*)1 - (long)(Singleton <T>*)(T*)1;
		inst=(T*)((long)this+offset);
	}
	~Singleton() { 
		inst=0;
	}
	static T& get()
	{
		static T singleInst;
		return singleInst;
	}
	static T *Ptr()
	{
		return inst;
	}
};

template<typename T> T* Singleton <T>::inst = 0;

#endif
