#ifndef STACKSEGMENT_H
#define STACKSEGMENT_H

#include "DzValue.h"

class StackSegment : public DzValue
{
	public:
		StackSegment(std::vector<DzValue *> values, DzValue *call, DzValue *consumer);

		bool compare(const DzValue *other, const EntryPoint &entryPoint) const override;

		std::vector<DzResult> build(const EntryPoint &entryPoint, Stack values) const override;

	private:
		std::vector<DzValue *> m_values;

		DzValue *m_call;
		DzValue *m_consumer;
};

#endif // STACKSEGMENT_H
