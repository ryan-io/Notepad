#include "textresetter.h"

IOResponse TextResetter::reset(File *file) { file->m_output.clear(); }
