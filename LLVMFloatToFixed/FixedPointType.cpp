#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Intrinsics.h"
#include "llvm/ADT/SmallPtrSet.h"
#include "llvm/Support/raw_ostream.h"
#include "FixedPointType.h"
#include "LLVMFloatToFixedPass.h"
#include <sstream>


using namespace llvm;
using namespace flttofix;


FixedPointType::FixedPointType()
{
  this->isSigned = false;
  this->fracBitsAmt = 0;
  this->bitsAmt = 0;
}


FixedPointType::FixedPointType(Type *llvmtype, bool signd)
{
  this->isSigned = signd;
  if (isFloatType(llvmtype)) {
    this->fracBitsAmt = 0;
    this->bitsAmt = 0;
    return;
  } else if (llvmtype->isIntegerTy()) {
    this->fracBitsAmt = 0;
    this->bitsAmt = llvmtype->getIntegerBitWidth();
  } else {
    this->isSigned = false;
    this->fracBitsAmt = 0;
    this->bitsAmt = 0;
  }
}


Type *FixedPointType::toLLVMType(LLVMContext& ctxt) const
{
  return Type::getIntNTy(ctxt, this->bitsAmt);
}


std::string FixedPointType::toString() const
{
  std::stringstream stm;
  if (isSigned)
    stm << "s";
  else
    stm << "u";
  stm << bitsAmt - fracBitsAmt << "_" << fracBitsAmt << "fixp";
  return stm.str();
}


raw_ostream& operator<<(raw_ostream& stm, const FixedPointType& f)
{
  stm << f.toString();
  return stm;
}


