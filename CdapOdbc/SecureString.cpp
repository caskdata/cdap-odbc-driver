/*
* Copyright � 2015 Cask Data, Inc.
*
* Licensed under the Apache License, Version 2.0 (the "License"); you may not
* use this file except in compliance with the License. You may obtain a copy of
* the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
* WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
* License for the specific language governing permissions and limitations under
* the License.
*/

#include "stdafx.h"
#include "SecureString.h"

void Cask::CdapOdbc::String::split(const SecureString& str, wchar_t delim, std::vector<SecureString>& tokens) {
  SecureStringStream stream(str.c_str());
  SecureString item;
  while (std::getline(stream, item, delim)) {
    tokens.push_back(item);
  }
}

std::wstring Cask::CdapOdbc::String::fromDouble(double value, int width) {
  std::wstringstream s;
  s << std::setw(width) << value;
  return s.str();
}
