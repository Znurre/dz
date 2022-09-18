#ifndef IPROTOTYPE_H
#define IPROTOTYPE_H

#include "Type.h"
#include "PrototypeField.h"
#include "NodeVisitor.h"

class EntryPoint;

class IPrototype : public Type
{
	public:
		virtual const IPrototype *root() const = 0;

		virtual std::vector<PrototypeField> fields(const EntryPoint &entryPoint, const DefaultNodeVisitor &visitor) const = 0;
};

#endif // IPROTOTYPE_H
