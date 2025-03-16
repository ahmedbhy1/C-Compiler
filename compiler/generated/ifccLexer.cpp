
// Generated from ifcc.g4 by ANTLR 4.13.2


#include "ifccLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct IfccLexerStaticData final {
  IfccLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  IfccLexerStaticData(const IfccLexerStaticData&) = delete;
  IfccLexerStaticData(IfccLexerStaticData&&) = delete;
  IfccLexerStaticData& operator=(const IfccLexerStaticData&) = delete;
  IfccLexerStaticData& operator=(IfccLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag ifcclexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<IfccLexerStaticData> ifcclexerLexerStaticData = nullptr;

void ifcclexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (ifcclexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(ifcclexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<IfccLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "T__9", "T__10", "RETURN", "ID", "CONST", "COMMENT", "DIRECTIVE", 
      "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'int'", "'main'", "'('", "')'", "'{'", "'}'", "'='", "';'", "'&'", 
      "'|'", "'^'", "'return'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "RETURN", "ID", "CONST", 
      "COMMENT", "DIRECTIVE", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,17,113,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,2,1,2,
  	1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,1,10,1,10,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,5,12,72,8,12,10,12,12,12,75,9,
  	12,1,13,4,13,78,8,13,11,13,12,13,79,1,14,1,14,1,14,1,14,5,14,86,8,14,
  	10,14,12,14,89,9,14,1,14,1,14,1,14,1,14,1,14,1,15,1,15,5,15,98,8,15,10,
  	15,12,15,101,9,15,1,15,1,15,1,15,1,15,1,16,4,16,108,8,16,11,16,12,16,
  	109,1,16,1,16,2,87,99,0,17,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,
  	10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,1,0,4,3,0,65,90,95,95,97,
  	122,4,0,48,57,65,90,95,95,97,122,1,0,48,57,3,0,9,10,13,13,32,32,117,0,
  	1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,
  	0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,
  	23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,
  	0,0,0,1,35,1,0,0,0,3,39,1,0,0,0,5,44,1,0,0,0,7,46,1,0,0,0,9,48,1,0,0,
  	0,11,50,1,0,0,0,13,52,1,0,0,0,15,54,1,0,0,0,17,56,1,0,0,0,19,58,1,0,0,
  	0,21,60,1,0,0,0,23,62,1,0,0,0,25,69,1,0,0,0,27,77,1,0,0,0,29,81,1,0,0,
  	0,31,95,1,0,0,0,33,107,1,0,0,0,35,36,5,105,0,0,36,37,5,110,0,0,37,38,
  	5,116,0,0,38,2,1,0,0,0,39,40,5,109,0,0,40,41,5,97,0,0,41,42,5,105,0,0,
  	42,43,5,110,0,0,43,4,1,0,0,0,44,45,5,40,0,0,45,6,1,0,0,0,46,47,5,41,0,
  	0,47,8,1,0,0,0,48,49,5,123,0,0,49,10,1,0,0,0,50,51,5,125,0,0,51,12,1,
  	0,0,0,52,53,5,61,0,0,53,14,1,0,0,0,54,55,5,59,0,0,55,16,1,0,0,0,56,57,
  	5,38,0,0,57,18,1,0,0,0,58,59,5,124,0,0,59,20,1,0,0,0,60,61,5,94,0,0,61,
  	22,1,0,0,0,62,63,5,114,0,0,63,64,5,101,0,0,64,65,5,116,0,0,65,66,5,117,
  	0,0,66,67,5,114,0,0,67,68,5,110,0,0,68,24,1,0,0,0,69,73,7,0,0,0,70,72,
  	7,1,0,0,71,70,1,0,0,0,72,75,1,0,0,0,73,71,1,0,0,0,73,74,1,0,0,0,74,26,
  	1,0,0,0,75,73,1,0,0,0,76,78,7,2,0,0,77,76,1,0,0,0,78,79,1,0,0,0,79,77,
  	1,0,0,0,79,80,1,0,0,0,80,28,1,0,0,0,81,82,5,47,0,0,82,83,5,42,0,0,83,
  	87,1,0,0,0,84,86,9,0,0,0,85,84,1,0,0,0,86,89,1,0,0,0,87,88,1,0,0,0,87,
  	85,1,0,0,0,88,90,1,0,0,0,89,87,1,0,0,0,90,91,5,42,0,0,91,92,5,47,0,0,
  	92,93,1,0,0,0,93,94,6,14,0,0,94,30,1,0,0,0,95,99,5,35,0,0,96,98,9,0,0,
  	0,97,96,1,0,0,0,98,101,1,0,0,0,99,100,1,0,0,0,99,97,1,0,0,0,100,102,1,
  	0,0,0,101,99,1,0,0,0,102,103,5,10,0,0,103,104,1,0,0,0,104,105,6,15,0,
  	0,105,32,1,0,0,0,106,108,7,3,0,0,107,106,1,0,0,0,108,109,1,0,0,0,109,
  	107,1,0,0,0,109,110,1,0,0,0,110,111,1,0,0,0,111,112,6,16,1,0,112,34,1,
  	0,0,0,6,0,73,79,87,99,109,2,6,0,0,0,1,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  ifcclexerLexerStaticData = std::move(staticData);
}

}

ifccLexer::ifccLexer(CharStream *input) : Lexer(input) {
  ifccLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *ifcclexerLexerStaticData->atn, ifcclexerLexerStaticData->decisionToDFA, ifcclexerLexerStaticData->sharedContextCache);
}

ifccLexer::~ifccLexer() {
  delete _interpreter;
}

std::string ifccLexer::getGrammarFileName() const {
  return "ifcc.g4";
}

const std::vector<std::string>& ifccLexer::getRuleNames() const {
  return ifcclexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& ifccLexer::getChannelNames() const {
  return ifcclexerLexerStaticData->channelNames;
}

const std::vector<std::string>& ifccLexer::getModeNames() const {
  return ifcclexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& ifccLexer::getVocabulary() const {
  return ifcclexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ifccLexer::getSerializedATN() const {
  return ifcclexerLexerStaticData->serializedATN;
}

const atn::ATN& ifccLexer::getATN() const {
  return *ifcclexerLexerStaticData->atn;
}




void ifccLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  ifcclexerLexerInitialize();
#else
  ::antlr4::internal::call_once(ifcclexerLexerOnceFlag, ifcclexerLexerInitialize);
#endif
}
