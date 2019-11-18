struct cd_objc2_list_header {
    uint32_t entsize;
    uint32_t count;
};

struct cd_objc2_image_info {
    uint32_t version;
    uint32_t flags;
};


//
// 64-bit, also holding 32-bit
//

// https://opensource.apple.com/source/objc4/objc4-756.2/runtime/objc-runtime-new.h.auto.html
// class is a Swift class from the pre-stable Swift ABI
#define FAST_IS_SWIFT_LEGACY    (1UL<<0)
// class is a Swift class from the stable Swift ABI
#define FAST_IS_SWIFT_STABLE    (1UL<<1)
// class or superclass has default retain/release/autorelease/retainCount/
//   _tryRetain/_isDeallocating/retainWeakReference/allowsWeakReference
#define FAST_HAS_DEFAULT_RR     (1UL<<2)
// data pointer
#define FAST_DATA_MASK          0x00007ffffffffff8UL

struct cd_objc2_class {
    uint64_t isa;
    uint64_t superclass;
    uint64_t cache;
    uint64_t vtable;
    uint64_t tagged_data; // points to class_ro_t
    uint64_t reserved1;
    uint64_t reserved2;
    uint64_t reserved3;
};

struct cd_objc2_class_ro_t {
    uint32_t flags;
    uint32_t instanceStart;
    uint32_t instanceSize;
    uint32_t reserved; // *** this field does not exist in the 32-bit version ***
    uint64_t ivarLayout;
    uint64_t name;
    uint64_t baseMethods;
    uint64_t baseProtocols;
    uint64_t ivars;
    uint64_t weakIvarLayout;
    uint64_t baseProperties;
};

struct cd_objc2_method {
    uint64_t name;
    uint64_t types;
    uint64_t imp;
};

struct cd_objc2_ivar {
    uint64_t offset;
    uint64_t name;
    uint64_t type;
    uint32_t alignment;
    uint32_t size;
};

struct cd_objc2_property {
    uint64_t name;
    uint64_t attributes;
};

struct cd_objc2_protocol {
    uint64_t isa;
    uint64_t name;
    uint64_t protocols;
    uint64_t instanceMethods;
    uint64_t classMethods;
    uint64_t optionalInstanceMethods;
    uint64_t optionalClassMethods;
    uint64_t instanceProperties; // So far, always 0
    uint32_t size; // sizeof(cd_objc2_protocol)
    uint32_t flags;
    uint64_t extendedMethodTypes;
};

struct cd_objc2_category {
    uint64_t name;
    uint64_t class;
    uint64_t instanceMethods;
    uint64_t classMethods;
    uint64_t protocols;
    uint64_t instanceProperties;
    uint64_t v7;
    uint64_t v8;
};
