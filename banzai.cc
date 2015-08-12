#include "packet.h"
#include "pipeline.h"
#include "atom.h"
#include "stage.h"

#include <vector>
#include <iostream>

int main(const int argc __attribute__ ((unused)), const char ** argv __attribute__((unused))) {
  /// Initialize field map to contain the right fields
  const Packet exemplar_packet(std::map<std::string, uint32_t>({{"a", 0}, {"b", 0}, {"c", 0}}));

  /// Generate random packets using this exemplar
  const auto random_packet = exemplar_packet.generate_random_packet();

  std::cerr << "Hello world" << std::endl;
  Pipeline pipeline({{Atom([](const Packet & p, State & s __attribute__((unused))) { return p; }, FieldContainer())}});
  pipeline.tick(random_packet);
}
