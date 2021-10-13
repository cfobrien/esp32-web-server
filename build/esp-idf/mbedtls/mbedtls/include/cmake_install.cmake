# Install script for directory: F:/esp/esp-idf/components/mbedtls/mbedtls/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/esp32-web-server")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/mbedtls" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/aes.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/aesni.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/arc4.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/aria.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/asn1.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/asn1write.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/base64.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/bignum.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/blowfish.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/bn_mul.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/camellia.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ccm.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/certs.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/chacha20.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/chachapoly.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/check_config.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/cipher.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/cipher_internal.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/cmac.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/compat-1.3.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/config.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ctr_drbg.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/debug.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/des.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/dhm.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecdh.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecdsa.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecjpake.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecp.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecp_internal.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/entropy.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/entropy_poll.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/error.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/gcm.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/havege.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/hkdf.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/hmac_drbg.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/md.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/md2.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/md4.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/md5.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/md_internal.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/memory_buffer_alloc.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/net.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/net_sockets.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/nist_kw.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/oid.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/padlock.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pem.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pk.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pk_internal.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pkcs11.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pkcs12.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pkcs5.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/platform.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/platform_time.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/platform_util.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/poly1305.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ripemd160.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/rsa.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/rsa_internal.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/sha1.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/sha256.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/sha512.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_cache.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_ciphersuites.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_cookie.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_internal.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_ticket.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/threading.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/timing.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/version.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509_crl.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509_crt.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509_csr.h"
    "F:/esp/esp-idf/components/mbedtls/mbedtls/include/mbedtls/xtea.h"
    )
endif()

