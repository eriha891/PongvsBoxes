#ifndef CATEGORY_HPP
#define CATEGORY_HPP


// Entity/scene node category, used to dispatch commands
namespace Category
{
        enum Type
        {
                None                                 = 0,
                Scene                                = 1 << 0,
                Player                               = 1 << 1,
                Ball                                 = 1 << 2,
                Block                                = 1 << 3,

        };
}

#endif // CATEGORY_HPP
