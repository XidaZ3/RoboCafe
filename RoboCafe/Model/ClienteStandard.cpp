#include "Model/ClienteStandard.h"

ClienteStandard::ClienteStandard()
{

}

ClienteStandard::~ClienteStandard(){}

Cliente* ClienteStandard::clone() const
{
    return new ClienteStandard(*this);
}
