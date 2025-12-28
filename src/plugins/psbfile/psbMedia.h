#pragma once
#include "StorageIntf.h"

// #include "SDL3/SDL.h"
#include <map>

namespace PSB {
    struct PSBMediaInfo
    {
        struct PSBMediaItemInfo
        {
            tjs_uint32 Offsets;
            tjs_uint32 Lengths;
        };
        std::map<ttstr, PSBMediaItemInfo> _resources;
    };

    class PSBMedia : public iTVPStorageMedia {
    public:
        PSBMedia() : refCount(1) {}

        virtual void TJS_INTF_METHOD AddRef() { refCount++; };

        virtual void TJS_INTF_METHOD Release()
        {
            if (refCount == 1)
            {
                delete this;
            }
            else
            {
                refCount--;
            }
        };

        // returns media name like "file", "http" etc.
        virtual void TJS_INTF_METHOD GetName(ttstr& name)
        {
            name = TJS_W("psb");
        }

        //	virtual ttstr IsCaseSensitive() = 0;
        // returns whether this media is case sensitive or not

        // normalize domain name according with the media's rule
        virtual void TJS_INTF_METHOD NormalizeDomainName(ttstr& name) override;

        // normalize path name according with the media's rule
        virtual void TJS_INTF_METHOD NormalizePathName(ttstr& name) override;

        // check file existence
        virtual bool TJS_INTF_METHOD CheckExistentStorage(const ttstr& name) override;

        // open a storage and return a tTJSBinaryStream instance.
        // name does not contain in-archive storage name but
        // is normalized.
        virtual tTJSBinaryStream* TJS_INTF_METHOD Open(const ttstr& name, tjs_uint32 flags) override;

        // list files at given place
        virtual void TJS_INTF_METHOD GetListAt(const ttstr& name,
                                               iTVPStorageLister* lister) override;

        // basically the same as above,
        // check wether given name is easily accessible from local OS filesystem.
        // if true, returns local OS native name. otherwise returns an empty string.
        virtual void TJS_INTF_METHOD GetLocallyAccessibleName(ttstr& name) override;

        void AddPSBFile(const ttstr& name, PSBMediaInfo data);
        void RemovePSBFile(const ttstr& name);

    protected:
        /**
         * デストラクタ
         */
        virtual ~PSBMedia() {}

    private:
        tjs_uint refCount; //< リファレンスカウント
        std::map<ttstr, PSBMediaInfo> _resources;
    };
}

extern PSB::PSBMedia* psbVar;