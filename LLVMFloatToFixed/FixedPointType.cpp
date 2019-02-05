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
  structData = nullptr;
  scalarData = {false, 0, 0};
}


FixedPointType::FixedPointType(bool s, int f, int b)
{
  structData = nullptr;
  scalarData = {s, f, b};
}


FixedPointType::FixedPointType(Type *llvmtype, bool signd)
{
  structData = nullptr;
  scalarData.isSigned = signd;
  if (isFloatType(llvmtype)) {
    scalarData.fracBitsAmt = 0;
    scalarData.bitsAmt = 0;
  } else if (llvmtype->isIntegerTy()) {
    scalarData.fracBitsAmt = 0;
    scalarData.bitsAmt = llvmtype->getIntegerBitWidth();
  } else {
    scalarData.isSigned = false;
    scalarData.fracBitsAmt = 0;
    scalarData.bitsAmt = 0;
  }
}


FixedPointType::FixedPointType(const llvm::ArrayRef<FixedPointType>& elems)
{
  structData.reset(new SmallVector<FixedPointType, 2>(elems.begin(), elems.end()));
}


Type *FixedPointType::scalarToLLVMType(LLVMContext& ctxt) const
{
  assert(!structData && "fixed point type not a scalar");
  return Type::getIntNTy(ctxt, scalarData.bitsAmt);
}


std::string FixedPointType::Primitive::toString() const
{
  std::stringstream stm;
  if (isSigned)
    stm << "s";
  else
    stm << "u";
  stm << bitsAmt - fracBitsAmt << "_" << fracBitsAmt << "fixp";
  return stm.str();
}


std::string FixedPointType::toString() const
{
  std::stringstream stm;
  
  if (!structData) {
    stm << scalarData.toString();
  } else {
    stm << '<';
    for (int i=0; i<structData->size(); i++) {
      stm << (*structData)[i].toString();
      if (i != structData->size()-1)
        stm << ',';
    }
    stm << '>';
  }
  
  return stm.str();
}


raw_ostream& operator<<(raw_ostream& stm, const FixedPointType& f)
{
  stm << f.toString();
  return stm;
}


bool FixedPointType::operator==(const FixedPointType& rhs) const
{
  if (!structData) {
    return scalarData == rhs.scalarData;
  } else {
    if (structData->size() != rhs.structData->size())
      return false;
    for (int i=0; i<structData->size(); i++) {
      if (!((*structData)[i] == (*rhs.structData)[i]))
        return false;
    }
  }
  return true;
}


