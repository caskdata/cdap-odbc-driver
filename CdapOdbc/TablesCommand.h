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

#include "Command.h"

namespace Cask {
  namespace CdapOdbc {

    /**
     * Gets a list of tables from a database.
     */
    class TablesCommand : public Command {

      std::map<std::wstring, std::wstring>* tableNames;

    public:

      /**
      * Creates a command instance.
      */
      TablesCommand(Connection* connection, std::map<std::wstring, std::wstring>& tableNames);

      /**
       * Executes a command and builds a data reader.
       */
      virtual std::unique_ptr<DataReader> executeReader() override;
    };
  }
}
