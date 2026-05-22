#ifndef ITEM_FACTORY_H
#define ITEM_FACTORY_H

#include <memory>

#include "item_parser.h"
#include "../models/item.h"

class ItemFactory {
    public:
        static std::unique_ptr<Item> criarItem(const DadosItem& dados);
};

#endif