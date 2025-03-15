#pragma once
#include <string>
#include <variant>
#include <optional>
#include <format>

namespace json_manip
{
    enum class TokenType
    {
        OpenBrace,
        CloseBrace,
        OpenBracket,
        CloseBracket,
        Colon,
        Comma,
        String,
        Number,
        True,
        False,
        Null,

        EndOfFile
    };



    using Lexeme = std::string;
    using Literal = std::optional<std::variant<std::string, double, bool>>;

    struct Token
    {
        TokenType type {};
        Lexeme lexeme {};
        Literal literal {};

        size_t position = 0;
    };

    std::string to_string(TokenType type);

    std::ostream& operator<<(std::ostream& os, const json_manip::TokenType& type);
    std::ostream& operator<<(std::ostream& os, const json_manip::Token& token);

}


template <>
struct std::formatter<json_manip::TokenType> : std::formatter<std::string>
{
    auto format(json_manip::TokenType type, std::format_context& ctx) const
    {
        return std::formatter<std::string>::format(to_string(type), ctx);
    }
};

