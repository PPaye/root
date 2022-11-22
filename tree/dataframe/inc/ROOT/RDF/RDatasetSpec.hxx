// Author: Vincenzo Eduardo Padulano CERN/UPV, Ivan Kabadzhov CERN  06/2022

/*************************************************************************
 * Copyright (C) 1995-2022, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

#ifndef ROOT_RDF_RDATASETSPEC
#define ROOT_RDF_RDATASETSPEC

#include <limits>
#include <string>
#include <utility> // std::pair
#include <vector>

#include <ROOT/RFriendInfo.hxx>
#include <RtypesCore.h> // Long64_t

namespace ROOT {
namespace RDF {
namespace Experimental {

class RDatasetSpec {

public:
   struct REntryRange {
      Long64_t fBegin{0};
      Long64_t fEnd{std::numeric_limits<Long64_t>::max()};
      REntryRange();
      REntryRange(Long64_t endEntry);
      REntryRange(Long64_t startEntry, Long64_t endEntry);
   };

private:
   /**
    * A list of names of trees.
    * This list should go in lockstep with fFileNameGlobs, only in case this dataset is a TChain where each file
    * contains its own tree with a different name from the global name of the dataset.
    * Otherwise, fTreeNames contains 1 treename, that is common for all file globs.
    */
   std::vector<std::string> fTreeNames;
   /**
    * A list of file names.
    * They can contain the globbing characters supported by TChain. See TChain::Add for more information.
    */
   std::vector<std::string> fFileNameGlobs;
   REntryRange fEntryRange;                  ///< Start (inclusive) and end (exclusive) entry for the dataset processing
   ROOT::TreeUtils::RFriendInfo fFriendInfo; ///< List of friends

public:
   RDatasetSpec(const std::string &treeName, const std::string &fileNameGlob, const REntryRange &entryRange = {});

   RDatasetSpec(const std::string &treeName, const std::vector<std::string> &fileNameGlobs,
                const REntryRange &entryRange = {});

   RDatasetSpec(const std::vector<std::pair<std::string, std::string>> &treeAndFileNameGlobs,
                const REntryRange &entryRange = {});

   void AddFriend(const std::string &treeName, const std::string &fileNameGlob, const std::string &alias = "");

   void
   AddFriend(const std::string &treeName, const std::vector<std::string> &fileNameGlobs, const std::string &alias = "");

   void AddFriend(const std::vector<std::pair<std::string, std::string>> &treeAndFileNameGlobs,
                  const std::string &alias = "");

   const std::vector<std::string> &GetTreeNames() const;
   const std::vector<std::string> &GetFileNameGlobs() const;
   Long64_t GetEntryRangeBegin() const;
   Long64_t GetEntryRangeEnd() const;
   const ROOT::TreeUtils::RFriendInfo &GetFriendInfo() const;
};

} // namespace Experimental
} // namespace RDF
} // namespace ROOT

#endif // ROOT_RDF_RDATASETSPEC