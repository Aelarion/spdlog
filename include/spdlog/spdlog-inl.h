// Copyright(c) 2015-present, Gabi Melman & spdlog contributors.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#pragma once

#ifndef SPDLOG_HEADER_ONLY
#    include <spdlog/spdlog.h>
#endif

#include <spdlog/common.h>

namespace spdlog {

// TODO what to do with flush_every ?
/*SPDLOG_INLINE void flush_every(std::chrono::seconds interval)
{
    details::registry::instance().flush_every(interval);
}*/


SPDLOG_INLINE void shutdown()
{
    // TODO call tp_ reset ?
    //details::registry::instance().shutdown();
}

SPDLOG_INLINE std::shared_ptr<spdlog::logger> default_logger()
{
    static std::shared_ptr<spdlog::logger> default_logger_ = std::make_shared<spdlog::logger>("");
    return default_logger_;
}

SPDLOG_INLINE logger *default_logger_raw()
{
    return default_logger().get(); //TODO remove this
}

SPDLOG_INLINE void set_default_logger(std::shared_ptr<spdlog::logger> default_logger)
{
    default_logger = std::move(default_logger);
}

} // namespace spdlog
