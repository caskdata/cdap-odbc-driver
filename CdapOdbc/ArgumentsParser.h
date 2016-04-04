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

#pragma once

namespace Cask {
  namespace CdapOdbc {
    class ArgumentsParser {

      ArgumentsParser() = delete;
      ArgumentsParser(const ArgumentsParser&) = delete;
      void operator=(const ArgumentsParser&) = delete;

      std::wstring arguments;

      bool isEscapedQuote(std::wstring query, size_t pos);
      bool isQuote(std::wstring query, size_t pos);
      bool isNestedBeginning(std::wstring query, size_t pos);
      bool Cask::CdapOdbc::ArgumentsParser::isNestedEnding(std::wstring query, size_t pos);
      bool Cask::CdapOdbc::ArgumentsParser::isNestedMatched(wchar_t begin, wchar_t end);

    public:

      /**
      * Creates an instance of the parser
      */
      ArgumentsParser(const std::wstring& argString);

      /**
      * Parses the string in format "<argument-1>[,<argument-2>...]" into separate arguments.
      */
      std::vector<std::wstring> GetArguments();

    };
  }
}
