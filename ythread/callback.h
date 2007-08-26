// callback.h
// Author: Allen Porter <allen@thebends.org>

#ifndef _YTHREAD_CALLBACK_H_
#define _YTHREAD_CALLBACK_H_

namespace ythread {

class Callback {
 public:
  virtual ~Callback() { }
  virtual void Execute() = 0;

 protected:
  Callback() { }
};

Callback* NewCallback(void (*func)());

template <class CLASS>
Callback* NewCallback(CLASS* object, void(CLASS::*func)());

// overload for additional arguments
template <class CLASS, class ARG>
Callback* NewCallback(CLASS* object, void(CLASS::*func)(ARG), ARG arg);

template <class ARG>
class Callback1 {
 public:
  virtual ~Callback1() { }
  virtual void Execute(ARG arg) = 0;

 protected:
  Callback1() { }
};

template <class CLASS, class ARG>
Callback1<ARG>* NewCallback(CLASS* object, void(CLASS::*func)(ARG));

}  // namespace ythread

#endif  // _YTHREAD_CALLBACK_H
