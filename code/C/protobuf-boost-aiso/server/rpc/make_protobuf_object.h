/*
 * Copyright © 2015 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License version 3,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Alberto Aguirre <alberto.aguirre@canonical.com>
 */

#ifndef KYDROID_RPC_MAKE_PROTOBUF_OBJECT_H_
#define KYDROID_RPC_MAKE_PROTOBUF_OBJECT_H_

#include <memory>

//kobe:  must be -std=c++14, not c++11
//https://blog.csdn.net/csfreebird/article/details/50411524

namespace kydroid {
namespace rpc {
template <typename ProtobufType>
auto make_protobuf_object() {
  return std::unique_ptr<ProtobufType>{ProtobufType::default_instance().New()};
}

template <typename ProtobufType>
auto make_protobuf_object(ProtobufType const& from) {
  auto object = make_protobuf_object<ProtobufType>();
  object->CopyFrom(from);
  return object;
}
}  // namespace rpc
}  // namespace kydroid

#endif
