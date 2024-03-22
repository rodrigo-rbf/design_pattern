#include "builder/person_builder.hpp"
#include "builder/person_address_builder.hpp"
#include "builder/person_job_builder.hpp"


Person_address_builder Person_builder_base::lives() const
{
  return Person_address_builder{ person };
}

Person_job_builder Person_builder_base::works() const
{
    return Person_job_builder{ person };
}

