#pragma once

#include "pl/internal/Macro.h"

namespace pl::symbol_provider {

void init();

/**
 * @brief Resolve a symbol name to a function address.
 *
 * @param symbolName [in] The symbol name.
 * @param printNotFound [in] Whether to print error message to console if the symbol is not found.
 * @return result The function address. nullptr if the function is not found.
 */
PLCAPI void* pl_resolve_symbol(const char* symbolName, bool printNotFound = true);

/**
 * @brief Get the symbol name of a function address.
 *
 * @param funcAddr [in] The function address.
 * @param resultLength [out, nullable] The addr of the length of the result. 0 if the function is not found.
 * @return result The result addr. The result is a null-terminated array of strings. nullptr
 * if the function is not found. The result should be freed by pl_free_lookup_result.
 */
PLCAPI const char* const* pl_lookup_symbol(void* func, size_t* resultLength);

/**
 * @brief Free the result of pl_lookup_symbol.
 *
 * @param result [in] The result of pl_lookup_symbol to free.
 */
PLCAPI void pl_free_lookup_result(const char* const* result);

} // namespace pl::symbol_provider
