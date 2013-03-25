#ifndef PYTHONCLASSES_H_
#define PYTHONCLASSES_H_

#include <boost/python.hpp>
#include "../physics/objectmgr.h"
#include "../gameplay/Player.h"

using namespace boost::python;

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(vector_overloads, operator*, 1, 1);

BOOST_PYTHON_MODULE(gl2)
{
  class_<ObjectMgr>("ObjectMgr")
  .def("add", &ObjectMgr::add)
  .def("set", &ObjectMgr::unload)
  //.def("detectCollision", &ObjectMgr::detectCollision)
  .def("find", &ObjectMgr::find)
  ;

  class_<Vector>("Vector")
  .def("__add__",&Vector::operator+)
  .def("__sub__",&Vector::operator-)
  .def("__mul__",&Vector::operator*, vector_overloads())
  .def("__div__",&Vector::operator/)
  .def("__mod__",&Vector::operator%)
  .def("angle",&Vector::angle)
  .def("normalize",&Vector::normalize)
  .def("calcNormal",&Vector::calcNormal)
  .def("magnitude",&Vector::magnitude)
  ;
  class_<Ship>("Ship", init<std::string,std::string,std::string,Vector,Vector,double,float>())
  .def("fireMissile",&Ship::fireMissile)
  .def("getHull", &Ship::getHull)
  ;
}

#endif /*PYTHONCLASSES_H_*/
