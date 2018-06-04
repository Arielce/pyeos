#ifndef __WASM_API_H__
#define __WASM_API_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <eosiolib/action.h>
#include <eosiolib/chain.h>
#include <eosiolib/crypto.h>
#include <eosiolib/db.h>
#include <eosiolib/permission.h>

struct wasm_api {
   uint32_t (*read_action_data)( void* msg, uint32_t len );
   uint32_t (*action_data_size)();
   void (*require_recipient)( account_name name );
   void (*require_auth)( account_name name );
   void (*require_auth2)( account_name name, permission_name permission );
   bool (*has_auth)( account_name name );
   bool (*is_account)( account_name name );
   void (*send_inline)(char *serialized_action, size_t size);
   void (*send_context_free_inline)(char *serialized_action, size_t size);
   uint64_t  (*publication_time)();
   account_name (*current_receiver)();
   uint32_t (*get_active_producers)( account_name* producers, uint32_t datalen );

   void (*assert_sha256)( char* data, uint32_t length, const checksum256* hash );
   void (*assert_sha1)( char* data, uint32_t length, const checksum160* hash );

   void (*assert_sha512)( char* data, uint32_t length, const checksum512* hash );
   void (*assert_ripemd160)( char* data, uint32_t length, const checksum160* hash );
   void (*sha256)( char* data, uint32_t length, checksum256* hash );
   void (*sha1)( char* data, uint32_t length, checksum160* hash );
   void (*sha512)( char* data, uint32_t length, checksum512* hash );
   void (*ripemd160)( char* data, uint32_t length, checksum160* hash );
   int (*recover_key)( const checksum256* digest, const char* sig, size_t siglen, char* pub, size_t publen );
   void (*assert_recover_key)( const checksum256* digest, const char* sig, size_t siglen, const char* pub, size_t publen );



   uint32_t (*db_store_i64)(account_name scope, table_name table, account_name payer, uint64_t id,  const void* data, uint32_t len);
   void (*db_update_i64)(int32_t iterator, account_name payer, const void* data, uint32_t len);
   void (*db_remove_i64)(int32_t iterator);
   uint32_t (*db_get_i64)(int32_t iterator, const void* data, uint32_t len);
   uint32_t (*db_next_i64)(int32_t iterator, uint64_t* primary);

   uint32_t (*db_previous_i64)(int32_t iterator, uint64_t* primary);
   uint32_t (*db_find_i64)(account_name code, account_name scope, table_name table, uint64_t id);
   uint32_t (*db_lowerbound_i64)(account_name code, account_name scope, table_name table, uint64_t id);

   uint32_t (*db_upperbound_i64)(account_name code, account_name scope, table_name table, uint64_t id);
   uint32_t (*db_end_i64)(account_name code, account_name scope, table_name table);
   uint32_t (*db_idx64_store)(account_name scope, table_name table, account_name payer, uint64_t id, const uint64_t* secondary);
   void (*db_idx64_update)(int32_t iterator, account_name payer, const uint64_t* secondary);

   void (*db_idx64_remove)(int32_t iterator);
   uint32_t (*db_idx64_next)(int32_t iterator, uint64_t* primary);
   uint32_t (*db_idx64_previous)(int32_t iterator, uint64_t* primary);
   uint32_t (*db_idx64_find_primary)(account_name code, account_name scope, table_name table, uint64_t* secondary, uint64_t primary);
   uint32_t (*db_idx64_find_secondary)(account_name code, account_name scope, table_name table, const uint64_t* secondary, uint64_t* primary);
   uint32_t (*db_idx64_lowerbound)(account_name code, account_name scope, table_name table, uint64_t* secondary, uint64_t* primary);
   uint32_t (*db_idx64_upperbound)(account_name code, account_name scope, table_name table, uint64_t* secondary, uint64_t* primary);
   uint32_t (*db_idx64_end)(account_name code, account_name scope, table_name table);
   uint32_t (*db_idx128_store)(account_name scope, table_name table, account_name payer, uint64_t id, const uint128_t* secondary);

   void (*db_idx128_update)(int32_t iterator, account_name payer, const uint128_t* secondary);
   void (*db_idx128_remove)(int32_t iterator);
   uint32_t (*db_idx128_next)(int32_t iterator, uint64_t* primary);
   uint32_t (*db_idx128_previous)(int32_t iterator, uint64_t* primary);
   uint32_t (*db_idx128_find_primary)(account_name code, account_name scope, table_name table, uint128_t* secondary, uint64_t primary);
   uint32_t (*db_idx128_find_secondary)(account_name code, account_name scope, table_name table, const uint128_t* secondary, uint64_t* primary);
   uint32_t (*db_idx128_lowerbound)(account_name code, account_name scope, table_name table, uint128_t* secondary, uint64_t* primary);
   uint32_t (*db_idx128_upperbound)(account_name code, account_name scope, table_name table, uint128_t* secondary, uint64_t* primary);

   uint32_t (*db_idx128_end)(account_name code, account_name scope, table_name table);
   uint32_t (*db_idx256_store)(account_name scope, table_name table, account_name payer, uint64_t id, const void* data, uint32_t data_len );
   void (*db_idx256_update)(int32_t iterator, account_name payer, const void* data, uint32_t data_len);
   void (*db_idx256_remove)(int32_t iterator);
   uint32_t (*db_idx256_next)(int32_t iterator, uint64_t* primary);

   uint32_t (*db_idx256_previous)(int32_t iterator, uint64_t* primary);
   uint32_t (*db_idx256_find_primary)(account_name code, account_name scope, table_name table, void* data, uint32_t data_len, uint64_t primary);
   uint32_t (*db_idx256_find_secondary)(account_name code, account_name scope, table_name table, const void* data, uint32_t data_len, uint64_t* primary);
   uint32_t (*db_idx256_lowerbound)(account_name code, account_name scope, table_name table, void* data, uint32_t data_len, uint64_t* primary);
   uint32_t (*db_idx256_upperbound)(account_name code, account_name scope, table_name table, void* data, uint32_t data_len, uint64_t* primary);
   uint32_t (*db_idx256_end)(account_name code, account_name scope, table_name table);
   uint32_t (*db_idx_double_store)(account_name scope, table_name table, account_name payer, uint64_t id, const double* secondary);
   void (*db_idx_double_update)(int32_t iterator, account_name payer, const double* secondary);
   void (*db_idx_double_remove)(int32_t iterator);
   uint32_t (*db_idx_double_next)(int32_t iterator, uint64_t* primary);
   uint32_t (*db_idx_double_previous)(int32_t iterator, uint64_t* primary);
   uint32_t (*db_idx_double_find_primary)(account_name code, account_name scope, table_name table, double* secondary, uint64_t primary);
   uint32_t (*db_idx_double_find_secondary)(account_name code, account_name scope, table_name table, const double* secondary, uint64_t* primary);
   uint32_t (*db_idx_double_lowerbound)(account_name code, account_name scope, table_name table, double* secondary, uint64_t* primary);
   uint32_t (*db_idx_double_upperbound)(account_name code, account_name scope, table_name table, double* secondary, uint64_t* primary);
   uint32_t (*db_idx_double_end)(account_name code, account_name scope, table_name table);
   uint32_t (*db_idx_long_double_store)(account_name scope, table_name table, account_name payer, uint64_t id, const long double* secondary);
   void (*db_idx_long_double_update)(int32_t iterator, account_name payer, const long double* secondary);
   void (*db_idx_long_double_remove)(int32_t iterator);
   uint32_t (*db_idx_long_double_next)(int32_t iterator, uint64_t* primary);
   uint32_t (*db_idx_long_double_previous)(int32_t iterator, uint64_t* primary);
   uint32_t (*db_idx_long_double_find_primary)(account_name code, account_name scope, table_name table, long double* secondary, uint64_t primary);
   uint32_t (*db_idx_long_double_find_secondary)(account_name code, account_name scope, table_name table, const long double* secondary, uint64_t* primary);
   uint32_t (*db_idx_long_double_lowerbound)(account_name code, account_name scope, table_name table, long double* secondary, uint64_t* primary);
   uint32_t (*db_idx_long_double_upperbound)(account_name code, account_name scope, table_name table, long double* secondary, uint64_t* primary);
   uint32_t (*db_idx_long_double_end)(account_name code, account_name scope, table_name table);


   uint32_t (*check_transaction_authorization)( const char* trx_data,     uint32_t trx_size,
                                    const char* pubkeys_data, uint32_t pubkeys_size,
                                    const char* perms_data,   uint32_t perms_size
                                  );
   uint32_t (*check_permission_authorization)( account_name account,
                                   permission_name permission,
                                   const char* pubkeys_data, uint32_t pubkeys_size,
                                   const char* perms_data,   uint32_t perms_size,
                                   uint64_t delay_us
                                 );
   int64_t (*get_permission_last_used)( account_name account, permission_name permission );
   int64_t (*get_account_creation_time)( account_name account );



   void (*prints)( const char* cstr );
   void (*prints_l)( const char* cstr, uint32_t len);
   void (*printi)( int64_t value );
   void (*printui)( uint64_t value );
   void (*printi128)( const int128_t* value );
   void (*printui128)( const uint128_t* value );
   void (*printsf)(float value);
   void (*printdf)(double value);
   void (*printqf)(const long double* value);
   void (*printn)( uint64_t name );
   void (*printhex)( const void* data, uint32_t datalen );

   void (*set_resource_limits)( account_name account, int64_t ram_bytes, int64_t net_weight, int64_t cpu_weight );
   int64_t (*set_proposed_producers)( char *producer_data, uint32_t producer_data_size );
   bool (*is_privileged)( account_name account );
   void (*set_privileged)( account_name account, bool is_priv );
   void (*set_blockchain_parameters_packed)(char* data, uint32_t datalen);
   uint32_t (*get_blockchain_parameters_packed)(char* data, uint32_t datalen);
   void (*activate_feature)( int64_t f );

   void (*eosio_assert)( uint32_t test, const char* msg );
   void (*eosio_assert_message)( uint32_t test, const char* msg, uint32_t msg_len );
   void (*eosio_assert_code)( uint32_t test, uint64_t code );
   void (*eosio_exit)( int32_t code );
   uint64_t  (*current_time)();
   uint32_t  (*now)();

   void (*send_deferred)(const uint128_t& sender_id, account_name payer, const char *serialized_transaction, size_t size, uint32_t replace_existing);
   int (*cancel_deferred)(const uint128_t& sender_id);
   size_t (*read_transaction)(char *buffer, size_t size);
   size_t (*transaction_size)();
   int (*tapos_block_num)();
   int (*tapos_block_prefix)();
   uint32_t (*expiration)();
   int (*get_action)( uint32_t type, uint32_t index, char* buff, size_t size );
   int (*get_context_free_data)( uint32_t index, char* buff, size_t size );
};

#ifdef __cplusplus
}
#endif

#endif