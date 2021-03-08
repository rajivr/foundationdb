/*
 * ActorFuzz.h
 *
 * This source file is part of the FoundationDB open source project
 *
 * Copyright 2013-2018 Apple Inc. and the FoundationDB project authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "flow/flow.h"
#include <vector>
#include "flow/actorcompiler.h"

using std::vector;

inline vector<int>& operator,(vector<int>& v, int a) {
	v.push_back(a);
	return v;
}

inline vector<int>& operator,(vector<int> const& v, int a) {
	return (const_cast<vector<int>&>(v), a);
}
inline void throw_operation_failed() {
	throw operation_failed();
}

// This is in dsltest.actor.cpp:
bool testFuzzActor(Future<int> (*actor)(FutureStream<int> const&, PromiseStream<int> const&, Future<Void> const&),
                   const char* desc,
                   vector<int> const& expectedOutput);

// This is defined by ActorFuzz.actor.cpp (generated by actorFuzz.py)
// Returns (tests passed, tests total)
std::pair<int, int> actorFuzzTests();

#include "flow/unactorcompiler.h"
