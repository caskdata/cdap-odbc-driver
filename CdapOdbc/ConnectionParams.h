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

    /**
     * Represents connection parameters parsed from connection string.
     */
    class ConnectionParams {
      std::wstring driver;
      std::wstring host;
      int port;
      std::wstring authToken;
      std::wstring namespace_;
      bool sslEnabled;
      bool verifySslCert;

      void parse(const std::wstring& connectionString);

      ConnectionParams(const ConnectionParams&) = delete;
      void operator=(const ConnectionParams&) = delete;

    public:

      /**
       * Creates an instance of connection params.
       */
      ConnectionParams(const std::wstring& connectionString);

      /**
       * Destructor.
       */
      ~ConnectionParams() = default;

      /**
      * Gets DRIVER connection parameter.
      */
      const std::wstring& getDriver() const {
        return this->driver;
      }

      /**
       * Gets HOST connection parameter.
       */
      const std::wstring& getHost() const {
        return this->host;
      }

      /**
       * Gets PORT connection parameter.
       */
      int getPort() const {
        return this->port;
      }

      /**
       * Gets AUTH_TOKEN connection parameter.
       */
      const std::wstring& getAuthToken() const {
        return this->authToken;
      }

      /**
       * Gets NAMESPACE connection parameter.
       */
      const std::wstring& getNamespace() const {
        return this->namespace_;
      }

      /**
       * Gets SSL_ENABLED connection parameter.
       */
      bool getSslEnabled() const {
        return this->sslEnabled;
      }

      /**
       * Gets VERIFY_SSL_CERT connection parameter.
       */
      bool getVerifySslCert() const {
        return this->verifySslCert;
      }

      /**
       * Gets full version of connection string.
       */
      std::wstring getFullConnectionString() const;
    };
  }
}