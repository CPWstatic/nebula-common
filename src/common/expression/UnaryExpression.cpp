/* Copyright (c) 2020 vesoft inc. All rights reserved.
 *
 * This source code is licensed under Apache 2.0 License,
 * attached with Common Clause Condition 1.0, found in the LICENSES directory.
 */

#include "common/expression/UnaryExpression.h"
#include "common/expression/VariableExpression.h"

namespace nebula {

bool UnaryExpression::operator==(const Expression& rhs) const {
    if (kind_ != rhs.kind()) {
        return false;
    }

    const auto& r = dynamic_cast<const UnaryExpression&>(rhs);
    return *operand_ == *(r.operand_);
}



void UnaryExpression::writeTo(Encoder& encoder) const {
    // kind_
    encoder << kind_;

    // operand_
    DCHECK(!!operand_);
    encoder << *operand_;
}


void UnaryExpression::resetFrom(Decoder& decoder) {
    // Read operand_
    operand_ = decoder.readExpression();
    CHECK(!!operand_);
}


const Value& UnaryExpression::eval(ExpressionContext& ctx) {
   switch (kind_) {
        case Kind::kUnaryPlus: {
            Value val(operand_->eval(ctx));
            result_ = std::move(val);
            break;
        }
        case Kind::kUnaryNegate: {
            result_ = -(operand_->eval(ctx));
            break;
        }
        case Kind::kUnaryNot: {
            result_ = !(operand_->eval(ctx));
            break;
        }
        case Kind::kUnaryIncr: {
            if (UNLIKELY(operand_->kind() != Kind::kVar
                        && operand_->kind() != Kind::kVersionedVar)) {
                result_ = Value(NullType::BAD_TYPE);
                break;
            }
            result_ = operand_->eval(ctx) + 1;
            auto* varExpr = static_cast<VariableExpression*>(operand_.get());
            ctx.setVar(varExpr->var(), result_);
            break;
        }
        case Kind::kUnaryDecr: {
            if (UNLIKELY(operand_->kind() != Kind::kVar
                        && operand_->kind() != Kind::kVersionedVar)) {
                result_ = Value(NullType::BAD_TYPE);
                break;
            }
            result_ = operand_->eval(ctx) - 1;
            auto* varExpr = static_cast<VariableExpression*>(operand_.get());
            ctx.setVar(varExpr->var(), result_);
            break;
        }
       default:
           LOG(FATAL) << "Unknown type: " << kind_;
   }
   return result_;
}

std::string UnaryExpression::toString() const {
    std::string op;
    switch (kind_) {
        case Kind::kUnaryPlus:
            op = "+";
            break;
        case Kind::kUnaryNegate:
            op = "-";
            break;
        case Kind::kUnaryNot:
            op = "!";
            break;
        case Kind::kUnaryIncr:
            op = "++";
            break;
        case Kind::kUnaryDecr:
            op = "--";
            break;
        default:
            op = "illegal symbol ";
    }
    std::stringstream out;
    out << op << "(" << operand_->toString() << ")";
    return out.str();
}

}  // namespace nebula
