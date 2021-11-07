#ifndef DZBOOLEANLITERAL_H
#define DZBOOLEANLITERAL_H

#include "DzValue.h"

class DzBooleanLiteral : public DzValue
{
	public:
		DzBooleanLiteral(DzValue *consumer, const std::string &value);

		int compare(DzValue *other, const EntryPoint &entryPoint) const override;

		std::vector<DzResult> build(const EntryPoint &entryPoint, Stack values) const override;

	private:
		const TypedValue *resolveValue(const EntryPoint &entryPoint) const;

		DzValue *m_consumer;

		std::string m_value;
};

#endif // DZBOOLEANLITERAL_H
