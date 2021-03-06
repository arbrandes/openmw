#ifndef GAME_MWBASE_JOURNAL_H
#define GAME_MWBASE_JOURNAL_H

#include <string>
#include <deque>
#include <map>

#include "../mwdialogue/journalentry.hpp"
#include "../mwdialogue/topic.hpp"
#include "../mwdialogue/quest.hpp"

namespace MWBase
{
    /// \brief Interface for the player's journal (implemented in MWDialogue)
    class Journal
    {
            Journal (const Journal&);
            ///< not implemented

            Journal& operator= (const Journal&);
            ///< not implemented

        public:

            typedef std::deque<MWDialogue::StampedJournalEntry> TEntryContainer;
            typedef TEntryContainer::const_iterator TEntryIter;
            typedef std::map<std::string, MWDialogue::Quest> TQuestContainer; // topc, quest
            typedef TQuestContainer::const_iterator TQuestIter;
            typedef std::map<std::string, MWDialogue::Topic> TTopicContainer; // topic-id, topic-content
            typedef TTopicContainer::const_iterator TTopicIter;

        public:

            Journal() {}

            virtual void clear() = 0;

            virtual ~Journal() {}

            virtual void addEntry (const std::string& id, int index) = 0;
            ///< Add a journal entry.

            virtual void setJournalIndex (const std::string& id, int index) = 0;
            ///< Set the journal index without adding an entry.

            virtual int getJournalIndex (const std::string& id) const = 0;
            ///< Get the journal index.

            virtual void addTopic (const std::string& topicId, const std::string& infoId) = 0;

            virtual TEntryIter begin() const = 0;
            ///< Iterator pointing to the begin of the main journal.
            ///
            /// \note Iterators to main journal entries will never become invalid.

            virtual TEntryIter end() const = 0;
            ///< Iterator pointing past the end of the main journal.

            virtual TQuestIter questBegin() const = 0;
            ///< Iterator pointing to the first quest (sorted by topic ID)

            virtual TQuestIter questEnd() const = 0;
            ///< Iterator pointing past the last quest.

            virtual TTopicIter topicBegin() const = 0;
            ///< Iterator pointing to the first topic (sorted by topic ID)
            ///
            /// \note The topic ID is identical with the user-visible topic string.

            virtual TTopicIter topicEnd() const = 0;
            ///< Iterator pointing past the last topic.
    };
}

#endif
