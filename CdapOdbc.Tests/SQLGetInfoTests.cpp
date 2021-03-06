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
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Cask {
  namespace CdapOdbc {
    namespace Tests {
      /**
       * Tests for SQLTables/SQLFetch/SQLBindCol functions.
       */
      TEST_CLASS(SQLGetInfoTests) {

      public:

        /**
         * Checks SQLTables succeeds for catalogs.
         */
        TEST_METHOD(GetDriverVerSucceeds) {
          int result;
          SQLHANDLE env = 0;
          SQLHANDLE con = 0;

          result = SQLAllocHandle(SQL_HANDLE_ENV, nullptr, &env);
          Assert::AreEqual(SQL_SUCCESS, result);

          result = SQLAllocHandle(SQL_HANDLE_DBC, env, &con);
          Assert::AreEqual(SQL_SUCCESS, result);

          wchar_t ver[100];
          short len;

          result = SQLGetInfoW(con, SQL_DRIVER_VER, ver, 100, &len);
          Assert::AreEqual(SQL_SUCCESS, result);
          Assert::AreEqual(10, static_cast<int>(len));
          Assert::AreNotEqual(L"00.00.0000", ver);

          SQLFreeHandle(SQL_HANDLE_DBC, con);
          SQLFreeHandle(SQL_HANDLE_ENV, env);
        }
      };
    }
  }
}