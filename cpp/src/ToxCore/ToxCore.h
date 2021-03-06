// Instance manager, JNI utilities.
#include "tox4j/Tox4j.h"

// Protobuf classes.
#include "Core.pb.h"

// JNI declarations from javah.
#include "generated/im_tox_tox4j_impl_jni_ToxCoreJni.h"

// Header from toxcore.
#include <tox/core.h>

#ifndef SUBSYSTEM
#define SUBSYSTEM TOX
#define CLASS     ToxCore
#define PREFIX    tox
#endif

namespace core
{
  namespace proto = im::tox::tox4j::core::proto;

  using Events = proto::CoreEvents;

  extern ToxInstances<tox::core_ptr, std::unique_ptr<Events>> instances;
}


template<typename T, size_t get_size (Tox const *), void get_data (Tox const *, T *)>
struct get_vector
{
  static bool register_funcs_0 ();

  static std::vector<T>
  make (Tox const *tox)
  {
    std::vector<T> name (get_size (tox));
    get_data (tox, name.data ());

    assert (register_funcs_0 ());

    return name;
  }
};

template<typename T, size_t get_size (Tox const *), void get_data (Tox const *, T *)>
bool
get_vector<T, get_size, get_data>::register_funcs_0 ()
{
  REGISTER_FUNCS (
    reinterpret_cast<uintptr_t> (make),
      "get_vector<" + get_func_name (get_size) + ", " + get_func_name (get_data) + ">"
  );

  return true;
};


template<std::size_t N>
struct constant_size
{
  static bool register_funcs_0 ();

  static std::size_t
  make (Tox const *)
  {
    assert (register_funcs_0 ());
    return N;
  }
};

template<std::size_t N>
bool
constant_size<N>::register_funcs_0 ()
{
  REGISTER_FUNCS (
    reinterpret_cast<uintptr_t> (make),
      "constant_size<" + std::to_string (N) + ">"
  );

  return true;
}
